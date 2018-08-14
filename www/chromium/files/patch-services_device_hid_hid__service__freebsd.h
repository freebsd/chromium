--- services/device/hid/hid_service_freebsd.h.orig	2018-03-04 05:38:54.468408000 +0100
+++ services/device/hid/hid_service_freebsd.h	2018-03-04 08:35:47.483290000 +0100
@@ -0,0 +1,48 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_SERVICE_FREEBSD_H_
+#define DEVICE_HID_HID_SERVICE_FREEBSD_H_
+
+#include <string>
+
+#include "base/macros.h"
+#include "base/memory/ref_counted.h"
+#include "base/memory/weak_ptr.h"
+#include "base/timer/timer.h"
+#include "services/device/hid/hid_service.h"
+#include "net/base/io_buffer.h"
+
+namespace device {
+
+class HidServiceFreeBSD : public HidService {
+ public:
+  HidServiceFreeBSD();
+  ~HidServiceFreeBSD() override;
+
+  void Connect(const std::string& device_guid,
+               const ConnectCallback& connect) override;
+  base::WeakPtr<HidService> GetWeakPtr() override;
+
+ private:
+  struct ConnectParams;
+  class BlockingTaskHelper;
+
+  static void OpenOnBlockingThread(std::unique_ptr<ConnectParams> params);
+  static void FinishOpen(std::unique_ptr<ConnectParams> params);
+  static void CreateConnection(std::unique_ptr<ConnectParams> params);
+
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  // |helper_| lives on the sequence |blocking_task_runner_| posts to and holds
+  // a weak reference back to the service that owns it.
+  std::unique_ptr<BlockingTaskHelper> helper_;
+  base::WeakPtrFactory<HidServiceFreeBSD> weak_factory_;
+
+  DISALLOW_COPY_AND_ASSIGN(HidServiceFreeBSD);
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_SERVICE_FREEBSD_H_