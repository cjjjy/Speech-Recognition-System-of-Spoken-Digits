// =====================================================================================
// 
//       Filename:  HMMSoftAutomaton.h
// 
//    Description:  This is Soft Automaton derived from HMMAutomaton
// 
//        Version:  0.01
//        Created:  2014/10/21 22时31分35秒
//       Revision:  none
//       Compiler:  clang 3.5
// 
//         Author:  wengsht (SYSU-CMU), wengsht.sysu@gmail.com
//        Company:  
// 
// =====================================================================================
#ifndef _AUTOGUARD_HMMSoftAutomaton_H_
#define _AUTOGUARD_HMMSoftAutomaton_H_

#include <vector>
#include "WaveFeatureOP.h"
#include "configure_hmm.h"
#include "HMMAutomaton.h"
#include "SoftState.h"
#include "DummyState.h"

class HMMSoftAutomaton : public HMMAutomaton {
    public:
        HMMSoftAutomaton(std::vector<WaveFeatureOP> *templates, int stateNum = AUTOMATON_STATE_NUM, int gaussNum = GAUSSIAN_NUM, int trainTimes = MAX_TRAIN_TIMES);
        ~HMMSoftAutomaton();

        void load(std::stringstream &in) {
            for(int i = 0;i <= stateNum ;i++) 
                for(int j = 0; j <= stateNum ;j++)
                    in >> transferCost[i][j];

            clearStates();

            states.push_back(new DummyState(templates));
            for(int idx = 1;idx <= stateNum;idx ++) {
                states.push_back(new SoftState(templates));
                states[idx]->load(in, gaussNum);
            }
        }

        void hmmTrain();
        double calcCost(WaveFeatureOP &input);
    private:
        inline SoftState *getState(int idx) {
            if(idx >= states.size()) return NULL;
            return (SoftState *)(states[idx]);
        }

        // 清除训练过程中的buffer
        void clearTrainBuffer() {
            alphaCost.clear();
            betaCost.clear();

            YustCost.clear();
            Ys2sNxtCost.clear();

            nodeCostTmp.clear();
        }

        // 计算alpha 和 beta 矩阵
        void beforeAlphaBeta(WaveFeatureOP & features);
        void calcAlphaBeta(WaveFeatureOP & features);

        // 清空一些总和的缓存器
        void initIterate();
        // 一次hmm 迭代
        bool iterateTrain();

        // 更新自动机的转移Cost矩阵
        bool updateTransfer();
        // 更新一个模板内部每个feature在各个state的概率
        // 累加每个模板对s状态出现概率综合的贡献(cost)
        void updateTemplateNode(int templateIdx);
        // 累加每个模板对transfer的贡献(cost)
        void updateTemplateTransfer(int templateIdx);

    private:
        // 所有u，所有t处于s的Cost和
        std::vector<double> YustCost;
        // 所有u，t， s转移到sNxt的概率的总和
        Matrix<double> Ys2sNxtCost;

        // 每次alpha 和beta迭代之前算好 当前template所有node的点cost
        // nodeCostTmp[s][t] 
        Matrix<double> nodeCostTmp;

        // alphaCost[s][t]  第s个状态, 第t个帧
        Matrix<double> alphaCost, betaCost;
};

#endif

