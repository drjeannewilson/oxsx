#include <PdfAxis.h>
#include <algorithm>

PdfAxis::PdfAxis(const std::string& name_, double min_, double max_, size_t nBins_,
                 const std::string& latexName_){
    fName = name_;
    fLatexName = latexName_;
    if(fLatexName == "")
        fLatexName = name_;
    fMin = min_;
    fMax = max_;
    fNBins = nBins_;
    fBinWidth =  double(fMax - fMin) /fNBins;

    fBinLowEdges.resize(fNBins, 0);    
    fBinHighEdges.resize(fNBins, 0);
    fBinCentres.resize(fNBins, 0);

    for(size_t i = 0; i < fNBins; i++){
        fBinLowEdges[i]  = fMin  + i          * fBinWidth;
        fBinCentres[i]   = fMin  + (i + 0.5)  * fBinWidth;
        fBinHighEdges[i] = fMin  + (i+1)      * fBinWidth;
    }
}

size_t PdfAxis::FindBin(double value_) const{
    size_t insertIndex = (size_t)((value_ - fBinLowEdges[0])/fBinWidth);
    if (insertIndex)
        return 0;
    if (insertIndex > fNBins -1)
        return fNBins -  1;
    return insertIndex;
}
