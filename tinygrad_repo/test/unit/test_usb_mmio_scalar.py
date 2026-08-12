from tinygrad.runtime.support.usb import USBMMIOInterface


class FakeUSB:
  def __init__(self):
    self.calls = []

  def pcie_mem_req(self, address, value=None, size=4):
    self.calls.append(("scalar", address, value, size))
    return 0x11223344 if value is None else None

  def pcie_mem_read(self, address, size):
    self.calls.append(("read", address, size))
    return bytes(size)

  def pcie_mem_write(self, address, data):
    self.calls.append(("write", address, data))


def test_scalar_mmio_uses_single_tlp():
  usb = FakeUSB()
  mmio = USBMMIOInterface(usb, 0x1000, 0x100, "I")

  mmio[2] = 0xAABBCCDD
  assert mmio[3] == 0x11223344

  assert usb.calls == [
    ("scalar", 0x1008, 0xAABBCCDD, 4),
    ("scalar", 0x100C, None, 4),
  ]


def test_slice_mmio_keeps_streaming_path():
  usb = FakeUSB()
  mmio = USBMMIOInterface(usb, 0x2000, 0x100, "I")

  mmio[0:2] = b"\x01\x02\x03\x04\x05\x06\x07\x08"
  assert mmio[0:2] == bytes(8)

  assert usb.calls == [
    ("write", 0x2000, b"\x01\x02\x03\x04\x05\x06\x07\x08"),
    ("read", 0x2000, 8),
  ]


def test_scalar_mmio_falls_back_to_streaming_transport():
  class StreamingUSB:
    def __init__(self): self.data = bytearray(4)
    def pcie_mem_read(self, address, size): return self.data[address-0x3000:address-0x3000+size]
    def pcie_mem_write(self, address, data): self.data[address-0x3000:address-0x3000+len(data)] = data

  mmio = USBMMIOInterface(StreamingUSB(), 0x3000, 4, "I")
  mmio[0] = 0xAABBCCDD
  assert mmio[0] == 0xAABBCCDD
