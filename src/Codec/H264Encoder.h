﻿/*
 * MIT License
 *
 * Copyright (c) 2016-2019 xiongziliang <771730766@qq.com>
 *
 * This file is part of ZLMediaKit(https://github.com/xiongziliang/ZLMediaKit).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef CODEC_H264ENCODER_H_
#define CODEC_H264ENCODER_H_

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
#include <x264.h>
#ifdef __cplusplus
}
#endif //__cplusplus

namespace mediakit {

class H264Encoder {
public:
    typedef struct {
        int iType;
        int iLength;
        uint8_t *pucData;
    } H264Frame;

    H264Encoder(void);
    virtual ~H264Encoder(void);
    bool init(int iWidth, int iHeight, int iFps);
    int inputData(char *apcYuv[3], int aiYuvLen[3], int64_t i64Pts, H264Frame **ppFrame);
private:
    x264_t* _pX264Handle = nullptr;
    x264_picture_t* _pPicIn = nullptr;
    x264_picture_t* _pPicOut = nullptr;
    H264Frame _aFrames[10];
};

} /* namespace mediakit */

#endif /* CODEC_H264ENCODER_H_ */
