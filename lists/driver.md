# Driver Packages

## Official

### install vulkan mesa driver
vulkan-radeon lib32-vulkan-radeon
vulkan-icd-loader lib32-vulkan-icd-loader
lib32-vulkan-intel lib32-vulkan-mesa-layers
vulkan-tools vulkan-intel vulkan-mesa-layers

### install acpi tools
acpi acpid acpi_call-dkms

### install intel-nvidia driver

```
echo "Install NVIDIA drivers first"
```
bumblebee primus lib32-primus
nvidia-prime bbswitch-dkms
primus_vk lib32-primus_vk
virtualgl lib32-virtualgl


--------------------------------------------------------------------------------

## AUR

### install gpu driver

#### nvidia-390 (utils,dkms,opencl)
- https://aur.archlinux.org/packages/nvidia-390xx-utils/
- https://aur.archlinux.org/packages/lib32-nvidia-390xx-utils/

