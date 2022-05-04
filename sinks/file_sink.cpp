#include "file_sink.h"

#include "acore/logging/formatters/default_path_formatter.h"

#include <fstream>

#ifndef __QNX__

#include "acore/std/filesystem.h"

#include <cstring>
#include <stdexcept>

namespace acore
{
namespace logging
{
    namespace sinks
    {
#endif

        FileSink::FileSink()
            : Sink()
        {
        }

        FileSink::FileSink(const std::string &pattern)
            : Sink()
#ifndef __QNX__
            , m_pathFormatter(
                  std::make_unique<formatters::DefaultPathFormatter>(pattern))
#else
    , m_pathFormatter(PathFormatterPtr(new DefaultPathFormatter(pattern)))
#endif
        {
        }

        FileSink::FileSink(PathFormatterPtr pathFormatter)
            : Sink()
            , m_pathFormatter(pathFormatter)
        {
        }

        FileSink::FileSink(const std::string &pattern,
                           MessageFormatterPtr messageFormatter)
            : Sink(messageFormatter)
#ifndef __QNX__
            , m_pathFormatter(
                  std::make_unique<formatters::DefaultPathFormatter>(pattern))
#else
    , m_pathFormatter(PathFormatterPtr(new DefaultPathFormatter(pattern)))
#endif
        {
        }

        FileSink::FileSink(PathFormatterPtr pathFormatter,
                           MessageFormatterPtr messageFormatter)
            : Sink(messageFormatter)
            , m_pathFormatter(pathFormatter)
        {
        }

        void FileSink::log(const std::string &message, level_t lvl)
        {
            std::string m_path = m_pathFormatter->format();

#ifdef __QNX__
            size_type slashPos = m_path.rfind('/');

            if (slashPos != string::npos)
            {
                std::string dirname = m_path.substr(0, m_path.rfind('/'));
                std::string cmd = "mkdir -p " + dirname;
                system(cmd.c_str());
            }
#else
    if (!filesystem::exists(m_path))
    {
        filesystem::create_directories(filesystem::path(m_path).parent_path());
    }
#endif

            std::ofstream out(m_path.c_str(), std::ofstream::app);

            if (!out.is_open())
            {
#ifdef __QNX__
                assert(false);
#else
        throw std::runtime_error(std::string("File open error: ") + m_path
                                 + std::strerror(errno));
#endif
            }

            out << message << std::endl;
        }

        void FileSink::flush()
        {
        }

#ifndef __QNX__
    } // namespace acore
} // namespace logging
} // namespace sinks
#endif