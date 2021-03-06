#ifndef EUDAQ_INCLUDED_FileReader
#define EUDAQ_INCLUDED_FileReader

#include "eudaq/FileSerializer.hh"
#include "eudaq/DetectorEvent.hh"
#include "eudaq/StandardEvent.hh"
#include "eudaq/counted_ptr.hh"
#include <string>

namespace eudaq {

  class DLLEXPORT FileReader {
    public:
      FileReader(const std::string & filename, const std::string & filepattern = "", bool synctriggerid = false);
      ~FileReader();
      bool NextEvent(size_t skip = 0);
      std::string Filename() const { return m_filename; }
      unsigned RunNumber() const;
      const eudaq::Event & GetEvent() const;
      const DetectorEvent & Event() const { return GetDetectorEvent(); } // for backward compatibility
      const DetectorEvent & GetDetectorEvent() const;
      const StandardEvent & GetStandardEvent() const;
      void Interrupt() { m_des.Interrupt(); }
      class eventqueue_t;
    private:
      std::string m_filename;
      FileDeserializer m_des;
      counted_ptr<eudaq::Event> m_ev;
      unsigned m_ver;
      eventqueue_t * m_queue;
  };

}

#endif // EUDAQ_INCLUDED_FileReader
