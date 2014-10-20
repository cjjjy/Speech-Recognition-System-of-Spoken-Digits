// =====================================================================================
// 
//       Filename:  WaveFeatureOPSet.h
// 
//    Description:  This class store a set of WaveFeatureOP
//                  iterator ++ : 遍历所有单词
//                  nextWord()  : 跳到下一个单词的库
// 
//        Version:  0.01
//        Created:  2014/10/20 07时43分14秒
//       Revision:  none
//       Compiler:  clang 3.5
// 
//         Author:  wengsht (SYSU-CMU), wengsht.sysu@gmail.com
//        Company:  
// 
// =====================================================================================
#ifndef _AUTOGUARD_WaveFeatureOPSet_H_
#define _AUTOGUARD_WaveFeatureOPSet_H_

#include <set>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Feature.h"

#include "WaveFeatureOP.h"
#include "SerialFiles.h"

class WaveFeatureOPSet {
    public:
        static int maxTemplatesPerWord;
        typedef std::map< std::string, std::vector<WaveFeatureOP> > dataSetType;
        class iterator {
            public:
                iterator() : dataSet(NULL), vecIdx(-1) { }
                iterator(dataSetType *dataSetPtr, dataSetType::iterator Itr, int idx) : dataSet(dataSetPtr), I(Itr), vecIdx(idx) {}

                WaveFeatureOP * operator *() {
                    std::vector<WaveFeatureOP> & tmpVec = I->second;

                    if(vecIdx >= 0 && vecIdx < tmpVec.size()) {
                        return &tmpVec[vecIdx];
                    }

                    return NULL;
                }
                const iterator & operator ++(int) {
                    ++ (*this);

                    return *this;
                }
                const iterator & operator ++() {
                    std::vector<WaveFeatureOP> & tmpVec = I->second;

                    vecIdx ++;
                    if(vecIdx >= maxTemplatesPerWord || vecIdx >= tmpVec.size()) {
                        nextWord();
                    }
                    if(I == dataSet->end())
                        vecIdx = -1;

                    return *this;
                }

                // 跳到下一个单词的templates库
                const iterator & nextWord() {
                    I ++;
                    vecIdx = 0;
                    if(I == dataSet->end())
                        vecIdx = -1;
                    return *this;
                }
                bool operator ==(const iterator & b) {
                    return vecIdx == b.vecIdx && I == b.I;
                }
                bool operator !=(const iterator & b) {
                    return !((*this) == (b));
                }

            private:
                dataSetType *dataSet;

                dataSetType::iterator I;

                int vecIdx;
        };
        // TODO better design for begin() and end() ?
        iterator begin() {
            _begin = iterator(&dataSet, dataSet.begin(), 0);
            return _begin;
        }
        iterator end() {
            _end = iterator(&dataSet, dataSet.end(), -1);

            return _end;
        }

        SP_RESULT loadMfccs(char *templateDir);
        SP_RESULT loadMfccs(char *templateDir, char *fileName);
        WaveFeatureOPSet();
        ~WaveFeatureOPSet();

private:
        iterator _begin, _end;
    bool loadMfccFromMfccFile(char * dir, char * wavFileName, char * word) {
        std::string mfccFileName;

        mfccFileName = SerialFiles::getMfccFileName(wavFileName);

        std::string tmpName = dir;
        tmpName += "/";
        tmpName += mfccFileName;

        std::ifstream FIN;
        
        FIN.open(tmpName, std::ios::in);

        if(FIN.fail() == true) {
            return false;
        }

        std::string tmp;
        std::vector<Feature> features;
        while(getline(FIN, tmp)) {
            std::stringstream sin(tmp);

            features.push_back(Feature());
            int idx = features.size() - 1;
            double value;

            while(sin >> value)
                features[idx].push_back(value);
        }

        tmpName = dir;
        tmpName += "/";
        tmpName += wavFileName;

        WaveFeatureOP newOp(features, tmpName, word);
        addWaveMfcc(word, newOp);

        FIN.close();

        return true;
    }
    void saveMfcc2MfccFile(char * dir, char * wavFileName, const std::vector<Feature> & features) {
        std::string mfccFileName;

        mfccFileName = SerialFiles::getMfccFileName(wavFileName);
        std::string tmpName = dir;
        tmpName += "/";
        tmpName += mfccFileName;

        std::ofstream FOUT(tmpName);

        std::string tmp;

        for(int i = 0;i < features.size(); i++) {
            std::stringstream sout("");
            if(features[i].size() == 0) continue;
            sout << features[i][0];

            for(int j = 1;j < features[i].size();j++) {
                sout << " ";
                sout << features[i][j];
            }
            
            FOUT << sout.str() << std::endl;
        }
        FOUT.close();
    }
private:
    void addWaveMfcc(char *word, WaveFeatureOP & newOP) {
        std::string wordStr = std::string(word);

        if(!dataSet.count(wordStr)) 
            dataSet[wordStr] = std::vector<WaveFeatureOP>();

        dataSet[wordStr].push_back(newOP);
    }

    dataSetType dataSet;
};

#endif