/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "SampleClass.hpp"

using std::cerr;
using std::endl;

SampleClass::SampleClass (int x) : sampleNum (x) { }

SampleClass::SampleClass (const SampleClass& OtherSample) : sampleNum (OtherSample.sampleNum) { }

SampleClass::~SampleClass () { }

void SampleClass::printNum ()
{
  cerr << sampleNum << endl;
}
