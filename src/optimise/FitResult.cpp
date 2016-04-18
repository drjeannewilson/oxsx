#include <FitResult.h>
#include <Histogram.h>
#include <iostream>
FitResult::~FitResult(){
    delete fStatSpace;
}

void
FitResult::SetBestFit(const std::vector<double>& bestFit_){
    fBestFit = bestFit_;
}

std::vector<double>
FitResult::GetBestFit() const{
    return fBestFit;
}

void
FitResult::SetStatSpace(const Histogram& statSpace_){
    fStatSpace = new Histogram(statSpace_);
}

const Histogram&
FitResult::GetStatSpace() const{
    return *fStatSpace;
}

FitResult
FitResult::operator=(const FitResult& other_){
    if (!fStatSpace)
        fStatSpace = NULL;
    else
        fStatSpace = new Histogram(*other_.fStatSpace);
    fIsValid = other_.fIsValid;
    fBestFit = other_.fBestFit;
    fStatSample = other_.fStatSample;
	fParameterNames = other_.fParameterNames;
    return *this;
}

FitResult::FitResult(const FitResult& other_){
    if (!other_.fStatSpace)
        fStatSpace = NULL;

    else
        fStatSpace = new Histogram(*other_.fStatSpace);
	fParameterNames = other_.fParameterNames;
    fStatSample = other_.fStatSample;
    fBestFit = other_.fBestFit;
    fIsValid = other_.fIsValid;
}

const std::vector<std::vector<double> >&
FitResult::GetStatSample() const{
    return fStatSample;
}

void
FitResult::SetStatSample(const std::vector<std::vector<double> >& statSample_){
    fStatSample = statSample_;
}

bool
FitResult::GetValid() const {
    return fIsValid;
}

void
FitResult::SetValid(bool b_){
    fIsValid = b_;
}

void
FitResult::SetParameterNames(const std::vector<std::string>& names_){
    fParameterNames = names_;
}

std::vector<std::string>
FitResult::GetParameterNames() const{
    return fParameterNames;
}

void
FitResult::Print() const{
  std::cout << fParameterNames.size() << "\t" << fBestFit.size() 
			<< std::endl;
    if(fParameterNames.size() != fBestFit.size())
        throw 0;

    std::cout << "Fit Result: " << std::endl;
    for(size_t i = 0; i < fParameterNames.size(); i++){
        std::cout << fParameterNames.at(i) << "\t" 
                  << fBestFit.at(i)
                  << std::endl;
    }        
}
