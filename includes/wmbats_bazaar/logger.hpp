/*!
 * @author wmbat@protonmail.com
 *
 * Copyright (C) 2019 Wmbat
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * You should have received a copy of the GNU General Public License
 * GNU General Public License for more details.
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BAZAAR_LOGGER_HPP
#define BAZAAR_LOGGER_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace bzr
{
    class logger
    {
    public:
        inline static void init( const char* logger_name, const char* display_pattern )
        {
            logger_ = spdlog::stdout_color_mt( logger_name );
            logger_->set_pattern( display_pattern );
        }

        inline static spdlog::logger& get_logger( )
        {
            return *logger_;
        }

    private:
        inline static std::shared_ptr<spdlog::logger> logger_;
    };
}

#endif // BAZAAR_LOGGER_HPP