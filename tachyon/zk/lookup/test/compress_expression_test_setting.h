#ifndef TACHYON_ZK_LOOKUP_TEST_COMPRESS_EXPRESSION_TEST_SETTING_H_
#define TACHYON_ZK_LOOKUP_TEST_COMPRESS_EXPRESSION_TEST_SETTING_H_

#include <memory>
#include <vector>

#include "tachyon/zk/expressions/evaluator/simple_evaluator.h"
#include "tachyon/zk/plonk/halo2/prover_test.h"

namespace tachyon::zk {

class CompressExpressionTestSetting : public halo2::ProverTest {
 public:
  void SetUp() override {
    halo2::ProverTest::SetUp();

    Table<Evals> columns(absl::MakeConstSpan(fixed_columns_),
                         absl::MakeConstSpan(advice_columns_),
                         absl::MakeConstSpan(instance_columns_));
    evaluator_ = {0, static_cast<int32_t>(prover_->domain()->size()), 1,
                  columns, absl::MakeConstSpan(challenges_)};
    theta_ = F(2);
  }

 protected:
  SimpleEvaluator<Evals> evaluator_;
  std::vector<Evals> fixed_columns_;
  std::vector<Evals> advice_columns_;
  std::vector<Evals> instance_columns_;
  std::vector<F> challenges_;
  F theta_;
};

}  // namespace tachyon::zk

#endif  // TACHYON_ZK_LOOKUP_TEST_COMPRESS_EXPRESSION_TEST_SETTING_H_
