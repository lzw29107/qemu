# core qdev-related obj files, also used by *-user and unit tests
hwcore_ss.add(files(
  'bus.c',
  'qdev-properties.c',
  'qdev.c',
  'resetcontainer.c',
  'resettable.c',
  'vmstate-if.c',
  # irq.c needed for qdev GPIO handling:
  'irq.c',
  'clock.c',
  'qdev-clock.c',
))

common_ss.add(files('cpu-common.c'))
common_ss.add(files('machine-smp.c'))
system_ss.add(when: 'CONFIG_FITLOADER', if_true: files('loader-fit.c'))
system_ss.add(when: 'CONFIG_GENERIC_LOADER', if_true: files('generic-loader.c'))
system_ss.add(when: 'CONFIG_GUEST_LOADER', if_true: files('guest-loader.c'))
system_ss.add(when: 'CONFIG_OR_IRQ', if_true: files('or-irq.c'))
system_ss.add(when: 'CONFIG_PLATFORM_BUS', if_true: files('platform-bus.c'))
system_ss.add(when: 'CONFIG_PTIMER', if_true: files('ptimer.c'))
system_ss.add(when: 'CONFIG_REGISTER', if_true: files('register.c'))
system_ss.add(when: 'CONFIG_SPLIT_IRQ', if_true: files('split-irq.c'))
system_ss.add(when: 'CONFIG_XILINX_AXI', if_true: files('stream.c'))
system_ss.add(when: 'CONFIG_PLATFORM_BUS', if_true: files('sysbus-fdt.c'))
system_ss.add(when: 'CONFIG_EIF', if_true: [files('eif.c'), zlib, libcbor, gnutls])

system_ss.add(files(
  'cpu-system.c',
  'fw-path-provider.c',
  'gpio.c',
  'hotplug.c',
  'loader.c',
  'machine-hmp-cmds.c',
  'machine-qmp-cmds.c',
  'machine.c',
  'nmi.c',
  'null-machine.c',
  'numa.c',
  'qdev-fw.c',
  'qdev-hotplug.c',
  'qdev-properties-system.c',
  'reset.c',
  'sysbus.c',
  'vm-change-state-handler.c',
  'clock-vmstate.c',
))
user_ss.add(files(
  'cpu-user.c',
  'qdev-user.c',
))
