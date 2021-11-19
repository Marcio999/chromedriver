// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_TEST_CHROMEDRIVER_COMMAND_LISTENER_PROXY_H_
#define CHROME_TEST_CHROMEDRIVER_COMMAND_LISTENER_PROXY_H_

#include <string>

#include "chrome/test/chromedriver/command_listener.h"

class CommandListenerProxy : public CommandListener {
 public:
  CommandListenerProxy(const CommandListenerProxy&) = delete;
  CommandListenerProxy& operator=(const CommandListenerProxy&) = delete;

  ~CommandListenerProxy() override;

  // |command_listener| must not be null.
  explicit CommandListenerProxy(CommandListener* command_listener);

  // Forwards commands to |command_listener_|.
  Status BeforeCommand(const std::string& command_name) override;

 private:
  CommandListener* const command_listener_;
};

#endif  // CHROME_TEST_CHROMEDRIVER_COMMAND_LISTENER_PROXY_H_
