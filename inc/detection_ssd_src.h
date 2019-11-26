/**
* @file detection_ssd_src.h
*
* Copyright (C) 2018. Huawei Technologies Co., Ltd. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef INC_DETECTION_SSD_SRC_H_
#define INC_DETECTION_SSD_SRC_H_
#include <hiaiengine/api.h>
#include <hiaiengine/multitype_queue.h>
#include "inc/common.h"
/*
* Source Engine
*/
class SourceEngine : public hiai::Engine
{
    /**
    * @ingroup SourceEngine
    * @brief SourceEngine Process function
    * @param [in]: SOURCE_ENGINE_INPUT_SIZE, Source Engine in port
    * @param [in]: SOURCE_ENGINE_OUTPUT_SIZE, Source Engine out port
    * @param [out]: HIAI_StatusT
    */
    HIAI_DEFINE_PROCESS(SOURCE_ENGINE_INPUT_SIZE, SOURCE_ENGINE_OUTPUT_SIZE)
};

#endif  // INC_DETECTION_SSD_SRC_H_
