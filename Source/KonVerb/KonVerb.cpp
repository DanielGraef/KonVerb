/*
  ==============================================================================

    KonVerb.cpp
    Created: 9 May 2014 10:09:46am
    Author:  Stefan Negele

  ==============================================================================
*/

#include "KonVerb.h"

KonVerb::KonVerb() {
  setVolume(1.0f);
}
KonVerb::~KonVerb() {}

void KonVerb::setVolume(float volume) {
  if(volume <= 1.0f)
    m_volume = volume;
  else
    m_volume = 1.0f;
}

void KonVerb::clockProcess(float* sample) {
  *sample *= m_volume;
}