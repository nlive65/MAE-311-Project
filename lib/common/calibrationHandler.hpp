//Interface for calibration to be inherited by each measurable component
#pragma once

namespace common{
    template <typename Collected_Data>
    class calibrationHandler_{
        private:
        Collected_Data basis_data[];
        public:
        calibrationHandler<Collected_Data>(double frequency,Collected_Data[] newBasis);
        ~calibrationHandler() = default;

    };

}