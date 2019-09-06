/*
 * Copyright 2019-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <folly/Executor.h>

namespace folly {
namespace coro {
namespace detail {
// Helper class that can be used to annotate Awaitable objects that will
// guarantee that they will be resumed on the correct executor so that
// when the object is awaited within a Task<T> it doesn't automatically
// wrap the Awaitable in something that forces a reschedule onto the
// executor.
template <typename Awaitable>
class UnsafeResumeInlineSemiAwaitable {
 public:
  explicit UnsafeResumeInlineSemiAwaitable(Awaitable&& awaitable) noexcept
      : awaitable_(awaitable) {}

  Awaitable&& viaIfAsync(folly::Executor::KeepAlive<>) && noexcept {
    return static_cast<Awaitable&&>(awaitable_);
  }

 private:
  Awaitable awaitable_;
};
} // namespace detail
} // namespace coro
} // namespace folly
