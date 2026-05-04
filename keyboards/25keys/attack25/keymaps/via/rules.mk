VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes

OPT_DEFS += -DENCODER_MAP_ENABLE
#ifeq ($(strip $(ENCODER_HOT_SWAP_ENABLE)), yes)
#	OPT_DEFS += -DENCODER_HOT_SWAP_ENABLE
#	OPT_DEFS += -DMATRIX_REMAP_ENABLE
#	SRC += ../common/matrix_remap.c
#endif

$(eval $(call ATTACK25_CUSTOMISE_MSG))
$(info )
