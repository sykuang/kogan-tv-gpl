A Sane README
===

**Warning:** Some of the other READMEs in this repo were provided by Kogan/Mstar and are non-sensical and/or generally wrong.

Prerequisites
===

If running OS X, install homebrew then:

    brew install coreutils xz

You will also need to obtain elfutils/libelf, ideally from AOSP.

__NOTE:__ The libelf provided by homebrew is not sufficient.

Compiling Android/Linux Kernel
===

Copy the pregenerated kernel config to the kernel sub-directory.

    cp .config_edison_SMP_android_emmc Kernel_updated/kernel/.config

Make sure a suitable ARM cross-compiling toolchain is in your PATH.

_Suitable toolchains are included in the AOSP project._ 

    cd Kernel_updated/kernel/
    
    export ARCH=arm
    export SUBARCH=arm
    export CROSS_COMPILE=arm-eabi-
    
    make -j4 HOSTCFLAGS=-i<PATH_TO_ELFUTILS>/libelf

Where you replace *&lt;PATH\_TO\_ELFUTILS&gt;* with the path to elfutils. If you have downloaded AOSP, elfutils is included in the external/ sub-directory.



Notes
===

 * Kernel_updated/kernel/Makefile has been modified as provided from Kogan/Mstar to skip running mpatch (Mstar's patching tool). This was done because the included binary is Linux only, but the necessary files to patch the kernel seem to be have been pregenerated and included anyway.

 * The source, as provided by Kogan, referred to a .config_edison_SMP_android_emmc, however no such file was provided. The .config_edison_SMP_android_emmc included in this repo was extracted from http://media.kogan.com/files/support_files/KALED473DSMTZA%20FIRMWARE%2020131107.zip
