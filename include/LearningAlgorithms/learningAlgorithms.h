//    File name: learningAlgorithms.h
//    (c) Rishabh Animesh, Skand Hurkat, Abhinandan Majumdar, Aayush Saxena, 2012

//    This file is part of EmoDetect.
//
//    EmoDetect is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    EmoDetect is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with EmoDetect. If not, see <http://www.gnu.org/licenses/>.

#ifndef __LEARNING_ALGORITHMS_H_INCLUDED
#define __LEARNING_ALGORITHMS_H_INCLUDED

#include <opencv2/opencv.hpp>
using namespace cv;
#include <Infrastructure/exceptions.h>

enum learningAlgorithm {ANN, SVM_ML, RT};

CvStatModel* learningAlgorithmSetup(int featureVectorSize,
    int numCategories,
    learningAlgorithm lA);

CvStatModel* readModel(const string& inputFile, learningAlgorithm lA);

void learningAlgorithmTrain(CvStatModel* model,
    const Mat& trainData,
    const Mat& responses,
    int numCategories,
    learningAlgorithm lA);

void learningAlgorithmPredict(CvStatModel* model,
    const Mat& featureData,
    Mat& responses,
    int numCategories,
    learningAlgorithm lA);

float learningAlgorithmComputeErrorRate(const Mat& predictedResponses,
    const Mat& actualResponses);

void writeModel(const CvStatModel* model, const string& outputFile);

#endif //__LEARNING_ALGORITHMS_H_INCLUDED
