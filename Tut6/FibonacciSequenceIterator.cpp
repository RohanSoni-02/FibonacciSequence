//
//  FibonacciSequenceIterator.cpp
//  Tut6
//
//  Created by Rohan Soni on 6/4/2022.
//

#include <stdio.h>
#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

using namespace std;

FibonacciSequenceIterator:: FibonacciSequenceIterator(const FibonacciSequence& aSequenceObject, uint64_t aStart):
fSequenceObject(aSequenceObject),
fIndex(aStart)
{}

FibonacciSequenceIterator:: FibonacciSequenceIterator(uint64_t aLimit, uint64_t aStart):
fSequenceObject(aLimit),
fIndex(aStart)
{}

const uint64_t& FibonacciSequenceIterator:: operator*() const
{
    return fSequenceObject.current() ;
}

FibonacciSequenceIterator&  FibonacciSequenceIterator::operator++()
{
    fSequenceObject.advance();
    fIndex++;
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++( int )
{
    FibonacciSequenceIterator temp = *this;
    ++(*this);
    return temp;
}
bool FibonacciSequenceIterator::operator==( const FibonacciSequenceIterator& aOther ) const
{
    return (fIndex== aOther.fIndex);
}
bool FibonacciSequenceIterator::operator!=( const FibonacciSequenceIterator& aOther) const
{
    return !(*this == aOther);
}

// iterator methods

// return new iterator positioned at start
FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
    FibonacciSequenceIterator Result = *this;
    Result.fSequenceObject.reset();
    Result.fIndex = 1;
    return Result;
}

// return new iterator positioned at limit
FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
    FibonacciSequenceIterator Result = *this;
    uint64_t flimit = fSequenceObject.getLimit();
    
    if (flimit !=0)
    {
        Result.fIndex = flimit +1;
    }
    
    else
    {
        Result.fIndex =0;
    }
    
    return Result;
}
