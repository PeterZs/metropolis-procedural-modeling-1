//#####################################################################
// Copyright 2009, Jerry Talton.
// This software is governed by the license contained in LICENSE.
//#####################################################################
#ifndef _STEM_4_SYMBOL_HPP_
#define _STEM_4_SYMBOL_HPP_

#include "Distributions.hpp"
#include "StemSymbol.hpp"

namespace ProceduralModeling{

//#####################################################################
// Class Stem_4Symbol
//#####################################################################
class Stem_4Symbol : public StemSymbol
{
public:
    Stem_4Symbol(Symbol** symbolTable)
     :StemSymbol(true,1,4,1,2,symbolTable)
    {}

    virtual void render(const float* params) const
    {
        float newParams[4]={
            Distributions::UniformSample(params[2]*1.5*0.6,params[2]*1.5,params[0]),
            1.2,
            params[1],
            2.0};
        StemSymbol::render(newParams);
    }

    virtual uint produce(const SymbolEntry* input,SymbolEntry* output,float& logProbability) const
    {
        output[0].mID=313;
        memcpy(output+1,input,sizeof(SymbolEntry)*3);
        logProbability=0;
        return 4;
    }

    virtual ushort setFlags(const float* params) const
    {
        return SymbolEntry::DETERMINISTIC;
    }

    virtual float logDiffusionProbability(const float* params) const
    {
        return log(Distributions::UniformEval(params[2]*1.5*0.6,params[2]*1.5,params[0]));
    }

    virtual void initGraphics()
    {
        StemSymbol::initGraphics();
    }

    virtual void saveToMesh(const float* params) const
    {
        float newParams[4]={
            Distributions::UniformSample(params[2]*1.5*0.6,params[2]*1.5,params[0]),
            1.2,
            params[1],
            2.0};
        StemSymbol::saveToMesh(newParams);
    }

    virtual void voxel(const float* params) const
    {
        float newParams[4]={
            Distributions::UniformSample(params[2]*1.5*0.6,params[2]*1.5,params[0]),
            1.2,
            params[1],
            2.0};
        StemSymbol::voxel(newParams);
    }

    virtual const char* symbolName() const
    { return "Stem_4"; }

//#####################################################################
};

//#####################################################################
} // namespace ProceduralModeling

#endif //_STEM_4_SYMBOL_HPP_
