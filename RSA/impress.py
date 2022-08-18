#!/usr/bin/env python
# coding: utf-8

# In[6]:


import os
import shutil
import argparse

# In[9]:





def main(args):
    RSA_size=args.RSA_size
    RADIX=args.RADIX
    test_type=args.test_type
    level=args.level
    if os.path.exists('generate_file'):
        shutil.rmtree('generate_file')
    os.mkdir('generate_file')
    assert(RSA_size in [1024,512,2048,4096])
    assert(RADIX in [256,512,1024])
    assert(RSA_size%RADIX==0)
    if RADIX==256:
        assert(1<=level<=4)
    elif RADIX==512:
        assert(1<=level<=5)
    else:
        assert(1<=level<=6)
    assert(test_type in ['default','self_defined'])
    source=os.path.join('rsa-'+str(RSA_size),'test.cpp')
    target=os.path.join('generate_file','test.cpp')
    shutil.copyfile(source, target)
    source=os.path.join('rsa-'+str(RSA_size),'test.hpp')
    target=os.path.join('generate_file','test.hpp')
    shutil.copyfile(source, target)
    source=os.path.join('rsa-'+str(RSA_size),'main.cpp')
    target=os.path.join('generate_file','main.cpp')
    shutil.copyfile(source, target)
    source=os.path.join('rsa-'+str(RSA_size),'asymmetric.hpp')
    target=os.path.join('generate_file','asymmetric.hpp')
    shutil.copyfile(source, target)
    karatsuba_file="mul%s_%s_level_karatsuba.cpp" %(RADIX,level)
    if test_type=='default':
        source=os.path.join('rsa-'+str(RSA_size),'default_modular.hpp')
        target=os.path.join('generate_file','modular.hpp')
        shutil.copyfile(source, target)
    else:
        source=os.path.join('rsa-'+str(RSA_size),'modular.hpp')
        target=os.path.join('generate_file','modular.hpp')
        f=open(source,'r+')
        flist=f.readlines()
        flist[26]="#include \""+karatsuba_file+"\"\n"
        flist[36]="const unsigned int RSA_SIZE=%s;\n" % RSA_size
        flist[37]="const unsigned int RADIX=%s;\n" %RADIX
        f.close()
        f = open(target, "w+")
        f.writelines(flist)
        f.close()
        source=os.path.join('radix_template',karatsuba_file)
        target=os.path.join('generate_file',karatsuba_file)
        shutil.copyfile(source, target)
    return


# In[10]:




# In[3]:


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--RSA_size', type=int, default=512)
    parser.add_argument('--RADIX', type=int, default=256)
    parser.add_argument('--level', type=int, default=2)
    parser.add_argument('--test_type', type=str, default='self_defined')
    args_ = parser.parse_args()
    main(args_) 


# In[4]:





# In[5]:





# In[ ]:




