/****************************************************************************************/
/* Hands out data from a simple root ntuple into an EventData object for each EventData */
/* reads directly to save the copy (though this happens only once anyway)               */
/****************************************************************************************/

#ifndef __OXSX_ROOT_NTUPLE__
#define __OXSX_ROOT_NTUPLE__
#include <DataSet.h>
#include <string>
#include <TFile.h>
#include <vector>

class EventData;
class TNtuple;
class ROOTNtuple : public DataSet{
 public:
    ROOTNtuple(const std::string& fileName_, const std::string& treeName_);
    ~ROOTNtuple();

    EventData GetEntry(size_t iEvent_) const;
    unsigned  GetNEntries() const;
    unsigned  GetNObservables() const;
    std::vector<std::string> GetObservableNames() const;

    void LoadBaskets();
    void DropBaskets();
    
 private:
    ROOTNtuple(const ROOTNtuple&);
    ROOTNtuple operator=(const ROOTNtuple&);

    TFile*   fROOTFile;
    TNtuple* fNtuple;
    
    EventData Assemble(size_t iEvent_) const;
};
#endif
