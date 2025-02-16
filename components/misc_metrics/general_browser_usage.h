/* Copyright (c) 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_MISC_METRICS_GENERAL_BROWSER_USAGE_H_
#define BRAVE_COMPONENTS_MISC_METRICS_GENERAL_BROWSER_USAGE_H_

#include <memory>
#include <optional>
#include <string>

#include "base/memory/raw_ptr.h"
#include "base/timer/wall_clock_timer.h"

class PrefRegistrySimple;
class PrefService;
class ISOWeeklyStorage;

namespace misc_metrics {

inline constexpr char kWeeklyUseHistogramName[] = "Brave.Core.WeeklyUsage";
inline constexpr char kProfileCountHistogramName[] = "Brave.Core.ProfileCount";

inline constexpr char kDayZeroVariantHistogramName[] = "Brave.DayZero.Variant";

// TODO(djandries): remove this metric when Nebula experiment is over
inline constexpr char kWeeklyUseNebulaHistogramName[] =
    "Brave.Core.WeeklyUsage.Nebula";

class GeneralBrowserUsage {
 public:
  GeneralBrowserUsage(PrefService* local_state,
                      std::optional<std::string> day_zero_experiment_variant,
                      bool is_first_run,
                      base::Time first_run_time);
  ~GeneralBrowserUsage();

  GeneralBrowserUsage(const GeneralBrowserUsage&) = delete;
  GeneralBrowserUsage& operator=(const GeneralBrowserUsage&) = delete;

  static void RegisterPrefs(PrefRegistrySimple* registry);

  void ReportProfileCount(size_t count);

 private:
  void ReportWeeklyUse();
  void ReportInstallTime();

  void SetUpUpdateTimer();

  void Update();

  raw_ptr<PrefService> local_state_;
  base::Time first_run_time_;
  std::unique_ptr<ISOWeeklyStorage> usage_storage_;

  base::WallClockTimer report_timer_;
};

}  // namespace misc_metrics

#endif  // BRAVE_COMPONENTS_MISC_METRICS_GENERAL_BROWSER_USAGE_H_
