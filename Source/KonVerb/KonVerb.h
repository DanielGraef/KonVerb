/*
  ==============================================================================

    KonVerb.h
    Created: 9 May 2014 10:09:46am
    Author:  Stefan Negele

  ==============================================================================
*/

#ifndef KONVERB_H_INCLUDED
#define KONVERB_H_INCLUDED

// doing only a volume control for easiness at beginning
class KonVerb {
public:
  KonVerb();
  ~KonVerb();

  //Parameters
  void setVolume(float volume);
  float getVolume(void){
    return m_volume;
  };

  //Use
  void clockProcess(float* sample);

private:
  float m_volume;
};


#endif  // KONVERB_H_INCLUDED
