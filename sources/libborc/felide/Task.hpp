#pragma once

#ifndef __borc_task_hpp__
#define __borc_task_hpp__

namespace borc {
    class Task {
    public:
        virtual ~Task();

        virtual void perform() = 0;
    };
}

#endif
