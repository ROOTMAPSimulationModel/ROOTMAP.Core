/////////////////////////////////////////////////////////////////////////////
// Name:        DummyPlantDA.cpp
// Purpose:     Definition of the DummyPlantDA class
// Created:     DD/MM/YYYY
// Author:      RvH
// $Date: 2008-06-16 02:07:36 +0800 (Mon, 16 Jun 2008) $
// $Revision: 1 $
// Copyright:   ?2006 University of Tasmania
/////////////////////////////////////////////////////////////////////////////
#include "simulation/data_access/dummyconfig/DummyPlantDA.h"
#include "simulation/data_access/dummyconfig/DummyCharacteristicDA.h"


namespace rootmap
{
    std::string DummyPlantDA::getTypeName() const
    {
        return m_typeName;
    }


    DoubleCoordinate DummyPlantDA::getOrigin() const
    {
        return m_origin;
    }


    DoubleCoordinate DummyPlantDA::getSeedLocation() const
    {
        return m_seedLocation;
    }


    ProcessTime_t DummyPlantDA::getSeedingTime() const
    {
        return m_seedingTime;
    }


    PossibleAxis* DummyPlantDA::getPossibleSeminals() const
    {
        // gives ownership to the caller
        PossibleAxis* tmp_ptr = m_possibleSeminals;
        // so that delete'ing is safe
        // Reason for using const_cast: this implementation is for dummies,
        // changing internal state on retrieving these will not be performed
        // in proper data classes. Removing the const from this method is not
        // a useful alternative
        const_cast<PossibleAxis *>(m_possibleSeminals) = 0;

        return tmp_ptr;
    }


    PossibleAxis* DummyPlantDA::getPossibleNodals() const
    {
        // gives ownership to the caller
        PossibleAxis* tmp_ptr = m_possibleNodals;
        // so that delete'ing is safe
        const_cast<PossibleAxis *>(m_possibleNodals) = 0;

        return tmp_ptr;
    }


    DummyPlantDA::DummyPlantDA
    (const std::string& name,
        const std::string& type_name,
        ProcessIdentifier identifier,
        ScoreboardStratum stratum,
        ProcessActivity activity,
        const DoubleCoordinate& origin,
        const DoubleCoordinate& seed_location,
        ProcessTime_t seeding_time,
        PossibleAxis* possible_seminals,
        PossibleAxis* possible_nodals)
        : DummyProcessDA(name, true, identifier, stratum, activity)
        , m_typeName(type_name)
        , m_origin(origin)
        , m_seedLocation(seed_location)
        , m_seedingTime(seeding_time)
        , m_possibleSeminals(possible_seminals)
        , m_possibleNodals(possible_nodals)
    {
    }


    DummyPlantDA::~DummyPlantDA()
    {
        delete m_possibleSeminals;
        delete m_possibleNodals;
    }
} /* namespace rootmap */

