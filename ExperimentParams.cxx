#include "ExperimentParams.hxx"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

unsigned CExperimentParams::getM() const
{
    return m_uM;
}

//==

unsigned CExperimentParams::getExperimentsCnt() const
{
    return m_uExperimentsCnt;
}

//==

float CExperimentParams::getProb() const
{
    return m_fProb;
}

//==

bool CExperimentParams::isValid() const
{
    return (m_uM * m_uExperimentsCnt * m_fProb) > 0;
}

//==

CExperimentParams::CExperimentParams()
    :m_uM(0)
    ,m_uExperimentsCnt(0)
    ,m_fProb(0)
{
    try
    {
        boost::property_tree::ptree expTree;
        boost::property_tree::read_xml("golomb_params.xml", expTree);
        m_uM = expTree.get<unsigned>("golomb.codec_param");
        m_uExperimentsCnt = expTree.get<unsigned>("golomb.experiments_cnt");
        m_fProb = expTree.get<float>("golomb.prob");
    }
    catch(...)
    {
        std::cerr << "Check whether golomb_params.xml exists and defines "
                  << "codec_param, experiments_cnt and prob properties"
                  << std::endl;
    }
}

