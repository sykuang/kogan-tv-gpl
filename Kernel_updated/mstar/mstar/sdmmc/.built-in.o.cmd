cmd_drivers/mstar/sdmmc/built-in.o :=  arm-none-linux-gnueabi-ld -EL    -r -o drivers/mstar/sdmmc/built-in.o drivers/mstar/sdmmc/ms_sdmmc_lnx.o drivers/mstar/sdmmc/src/hal_card_platform.o drivers/mstar/sdmmc/src/hal_card_regs.o drivers/mstar/sdmmc/src/hal_card_timer.o drivers/mstar/sdmmc/src/hal_card_intr.o drivers/mstar/sdmmc/src/hal_sdmmc.o ; scripts/mod/modpost drivers/mstar/sdmmc/built-in.o
