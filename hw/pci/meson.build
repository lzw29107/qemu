pci_ss = ss.source_set()
pci_ss.add(files(
  'msi.c',
  'msix.c',
  'pci.c',
  'pci_bridge.c',
  'pci_host.c',
  'pci-hmp-cmds.c',
  'pci-qmp-cmds.c',
  'pcie_sriov.c',
  'shpc.c',
  'slotid_cap.c'
))
# The functions in these modules can be used by devices too.  Since we
# allow plugging PCIe devices into PCI buses, include them even if
# CONFIG_PCI_EXPRESS=n.
pci_ss.add(files('pcie.c', 'pcie_aer.c'))
pci_ss.add(files('pcie_doe.c'))
system_ss.add(when: 'CONFIG_PCI_EXPRESS', if_true: files('pcie_port.c', 'pcie_host.c'))
system_ss.add_all(when: 'CONFIG_PCI', if_true: pci_ss)

system_ss.add(when: 'CONFIG_PCI', if_false: files('pci-stub.c'))
