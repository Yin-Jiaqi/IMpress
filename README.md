# IMpress Re-test

## Case study: RSA

```bash
    assert(RSA_size in [1024,512,2048,4096])
    assert(RADIX in [256,512,1024])
    assert(RSA_size%RADIX==0)
    if RADIX==256:
        assert(1<=level<=4)
    elif RADIX==512:
        assert(1<=level<=5)
    else:
        assert(1<=level<=6)
```

level: keratsuba level


1. Run impress.py (RSA folder) to generate template file. Default RSA-size=512, RADIX=256, level=2 which generate file under 'generate_file' folder

2. Replace modular.hpp, asymmetric.hpp,mul(RSA_size)_(level)_level_karatsuba.cpp   file in foler: Vitis_Libraries/security/L1/include/xf_security and also change main.cpp,test.hpp, and test.cpp files in folder: Vitis_Libraries/security/L1/tests/rsa/ with the given files for each RSA size.

3. Set your own device, Revision, work_folder in file Vitis_Libraries/security/L1/tests/rsa/setting.tcl

4. cd Vitis_Libraries/security/L1/tests/rsa

Start simulation by 'vitis_hls run_hls.tcl'
