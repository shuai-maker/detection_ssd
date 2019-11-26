/**
* @file detection_ssd_ai_engine.h
*
* Copyright (C) 2018. Huawei Technologies Co., Ltd. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef INC_DETECTION_SSD_AI_ENGINE_H_
#define INC_DETECTION_SSD_AI_ENGINE_H_
#include <hiaiengine/api.h>
#include <hiaiengine/ai_model_manager.h>
#include <string>
#include <vector>
#include <map>
#include "inc/common.h"

class DetectionSSDEngine : public hiai::Engine
{
 public:
    /**
    * @ingroup DetectionSSDEngine
    * @brief DetectionSSDEngine init function
    * @param [in]:config, Configuration parameters
    * @param [in]: model_desc, Model Description
    * @param [out]: HIAI_StatusT
    */
    HIAI_StatusT Init(const hiai::AIConfig &config,
        const std::vector<hiai::AIModelDescription>& model_desc);

    /**
    * @ingroup DetectionSSDEngine
    * @brief DetectionSSDEngine execute function
    * @param [in]: DETECTIONSSD_ENGINE_INPUT_SIZE, numbers of in port
    * @param [in]: DETECTIONSSD_ENGINE_OUTPUT_SIZE, numbers of out port
    * @param [out]: HIAI_StatusT
    */
    HIAI_DEFINE_PROCESS(DETECTIONSSD_ENGINE_INPUT_SIZE, DETECTIONSSD_ENGINE_OUTPUT_SIZE);
 private:
    std::map<std::string, std::string> config_;                 // config map
    std::shared_ptr<hiai::AIModelManager> ai_model_manager_;    // Model Manager Instance
};

#endif  // INC_DETECTION_SSD_AI_ENGINE_H_
