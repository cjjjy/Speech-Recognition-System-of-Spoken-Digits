// =====================================================================================
// 
//       Filename:  HMMAutomatonSet.cpp
// 
//    Description:  
// 
//        Version:  0.01
//        Created:  2014/10/21 21时49分31秒
//       Revision:  none
//       Compiler:  clang 3.5
// 
//         Author:  wengsht (SYSU-CMU), wengsht.sysu@gmail.com
//        Company:  
// 
// =====================================================================================

#include "HMMAutomatonSet.h"
#include "HMMKMeanAutomaton.h"
#include "HMMSoftAutomaton.h"
#include <string>
#include <iostream>

HMMAutomatonSet::HMMAutomatonSet(int stateNum, int gaussNum, int trainTimes) : stateNum(stateNum), gaussNum(gaussNum), trainTimes(trainTimes) {
}
HMMAutomatonSet::~HMMAutomatonSet() {
}


SP_RESULT HMMAutomatonSet::train() {
    clear();

    dataSetType::iterator templateItr;

    for(templateItr = dataSet.begin(); templateItr != dataSet.end(); templateItr ++) {
        std::string word = templateItr->first;

        if(automatons.count(word))
            continue;
        // 新建自动机
        if(stateType == HMMState::KMEAN)
            automatons[word] = new HMMKMeanAutomaton(&(templateItr->second), stateNum, trainTimes); 
        else 
            automatons[word] = new HMMSoftAutomaton(&(templateItr->second), stateNum, trainTimes); 

        automatons[word]->hmmTrain();
    }
    return SP_SUCCESS;
}

std::string HMMAutomatonSet::recognition(std::vector<Feature> & input) {
    return "null2";
}

void HMMAutomatonSet::clear() {
    std::map< std::string, HMMAutomaton *>::iterator Itr;

    for(Itr = automatons.begin(); Itr != automatons.end(); Itr ++) {

        (Itr->second)->close();

        delete (Itr->second);
    }
    automatons.clear();
}