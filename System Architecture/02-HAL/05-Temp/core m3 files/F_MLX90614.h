#ifndef F_MLX90614_H
#define F_MLX90614_H

#include "STD_TYPES.h"

#define   MLX90614_ADDR         0x5A
#define   MLX90614_ADDR_WRITE   0x00	
#define   MLX90614_ADDR_READ    0x01

#define   MLX90614_RAM          0x00

#define   AMBIENT_TEMP          0x06
#define   OBJECT_TEMP           0x07


f32 MLX90614_READ(u8 ambient_or_object);

#endif
