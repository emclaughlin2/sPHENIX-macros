#include <TString.h>
//#include "BbcCDB.C"
#include "mbd/MbdCalib.h"

#if defined(__CLING__)
R__LOAD_LIBRARY(libmbd_io.so)
R__LOAD_LIBRARY(libmbd.so)
#endif

void make_cdbtree(const char *calibfname)
{
  TString calfname = calibfname;
  MbdCalib *cal = new MbdCalib();
  //cal->Verbosity(10);

  if ( calfname.Contains("sampmax") )
  {
    //Read_SampMax( calibfname );
    cal->Download_SampMax( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_sampmax.calib","mbd_sampmax.root");
    cout << cdbfname << endl;
    cal->Write_CDB_SampMax( cdbfname.Data() );
  }
  else if ( calfname.Contains("tt_t0") )
  {
    cal->Download_TTT0( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_tt_t0.calib","mbd_tt_t0.root");
    cout << cdbfname << endl;
    cal->Write_CDB_TTT0( cdbfname.Data() );
  }
  else if ( calfname.Contains("tq_t0") )
  {
    cal->Download_TQT0( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_tq_t0.calib","mbd_tq_t0.root");
    cout << cdbfname << endl;
    cal->Write_CDB_TQT0( cdbfname.Data() );
  }
  else if ( calfname.Contains("timecorr") )
  {
    cal->Download_TimeCorr( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_timecorr.calib","mbd_timecorr.root");
    cout << cdbfname << endl;
    cal->Write_CDB_TimeCorr( cdbfname.Data() );
  }
  else if ( calfname.Contains("slewcorr") )
  {
    cal->Download_SlewCorr( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_slewcorr.calib","mbd_slewcorr.root");
    cout << cdbfname << endl;
    cal->Write_CDB_SlewCorr( cdbfname.Data() );
  }
  else if ( calfname.Contains("qfit") )
  {
    cal->Download_Gains( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_qfit.calib","mbd_qfit.root");
    //cdbfname.ReplaceAll(".root",".calib");
    cout << cdbfname << endl;
    cal->Write_CDB_Gains( cdbfname.Data() );
    //cal->Write_Gains( cdbfname.Data() );
  }
  else if ( calfname.Contains("shape") )
  {
    cal->Download_Shapes( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("bbc_shape.calib","mbd_shape.root");
    cout << cdbfname << endl;
    //cdbfname = "mbd_shape.root";
    cal->Write_CDB_Shapes( cdbfname.Data() );
  }
  else if ( calfname.Contains("t0corr") )
  {
    cal->Download_T0Corr( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_t0corr.calib","mbd_t0corr.root");
    cout << cdbfname << endl;
    //cdbfname = "mbd_t0corr.root";
    cal->Write_CDB_T0Corr( cdbfname.Data() );
  }
  else if ( calfname.Contains("pileup") )
  {
    cal->Download_Pileup( calibfname );
    TString cdbfname = calibfname;
    cdbfname.ReplaceAll("mbd_pileup.calib","mbd_pileup.root");
    cout << cdbfname << endl;
    //cdbfname = "mbd_pileup.root";
    cal->Write_CDB_Pileup( cdbfname.Data() );
  }

}

