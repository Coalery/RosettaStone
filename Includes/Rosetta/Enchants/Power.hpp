// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_POWER_HPP
#define ROSETTASTONE_POWER_HPP

#include <Rosetta/Enchants/Enchant.hpp>

#include <vector>

namespace RosettaStone
{
class ITask;
class Enchant;

//!
//! \brief Power class.
//!
//! This class stores task to perform power and enchant to apply it.
//!
class Power
{
 public:
    //! Returns enchant.
    //! \return A reference to enchant.
    Enchant& GetEnchant();

    //! Returns a list of power tasks.
    //! \return A list of power tasks.
    std::vector<ITask*>& GetPowerTask();

    //! Returns a list of deathrattle tasks.
    //! \return A list of deathrattle tasks.
    std::vector<ITask*>& GetDeathrattleTask();

    //! Clears power task and enchant.
    void ClearData();

    //! Adds enchant.
    //! \param enchant An enchant to add.
    void AddEnchant(Enchant&& enchant);

    //! Adds power task.
    //! \param task A pointer to power task.
    void AddPowerTask(ITask* task);

    //! Adds deathrattle task.
    //! \param taks A pointer to deathrattle task.
    void AddDeathrattleTask(ITask* task);

 private:
    Enchant m_enchant;

    std::vector<ITask*> m_powerTask;
    std::vector<ITask*> m_deathrattleTask;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_POWER_HPP
