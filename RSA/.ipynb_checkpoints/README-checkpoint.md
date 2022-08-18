# High-radix and HLS-level RSA Encryption benchmark with adjustable radix and suitable for Vitis Security library

HLS-level RSA benchmark implementations for 512, 1024, 2048 and 4096-bit key sizes.


## Before running the RSA benchmark, download the Vitis Security Library
First Vitis Security Library needs to be downloaded.

```bat
git clone https://github.com/Xilinx/Vitis_Libraries.git
cd Vitis_Libraries
git checkout master
cd security
```

## Change the rsa files in the Vitis library
Replace ``modular.hpp`` file in foler:
`Vitis_Libraries/security/L1/include/xf_security`
and
also change ``main.cpp``, ``test.hpp``, and ``test.cpp`` files in folder:
`Vitis_Libraries/security/L1/tests/rsa/`
with the given files for each RSA size.

## Environment Setup
Vitis, XRT and platform paths should be specified in your terminal
before running the test.

```bat
source /opt/xilinx/Vitis/2021.1/settings64.sh
source /opt/xilinx/xrt/setup.sh
export PLATFORM_REPO_PATHS=/opt/xilinx/platforms
```

## In order to run the RSA Encryption benchmark:
You can follow the commands below to run the simulation of the RSA
Encryption benchmark and you need to see "Test is SUCCESSFUL !!!"
text at the end of simulation log.

```bat
cd L1/tests/rsa
make run CSIM=1 CSYNTH=0 COSIM=0 VIVADO_SYN=0 VIVADO_IMPL=0 DEVICE=xilinx_u280_xdma_201920_3
```


