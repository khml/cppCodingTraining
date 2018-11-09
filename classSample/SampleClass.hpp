/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SAMPLECLASS_HPP
#define SAMPLECLASS_HPP

class SampleClass 
{
public:
    SampleClass(int);
    SampleClass(const SampleClass&);
    virtual ~SampleClass();
    int const sampleNum;
    void printNum();
private:

};

#endif /* SAMPLECLASS_HPP */

