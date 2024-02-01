//
// Copyright (c) 2020 Kasper Laudrup (laudrup at stacktrace dot dk)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_WINTLS_DETAIL_CONFIG_HPP
#define BOOST_WINTLS_DETAIL_CONFIG_HPP

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#endif // __clang__
#ifdef WINTLS_USE_STANDALONE_ASIO
#include <system_error>
#include <asio.hpp>
#else // WINTLS_USE_STANDALONE_ASIO
#include <boost/config.hpp>
#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>
#include <boost/asio.hpp>
#endif // !WINTLS_USE_STANDALONE_ASIO
#ifdef __clang__
#pragma clang diagnostic pop
#endif // __clang__

#ifndef __MINGW32__
#pragma comment(lib, "crypt32")
#pragma comment(lib, "secur32")
#endif // !__MINGW32__

namespace boost {
namespace wintls {
#ifdef WINTLS_USE_STANDALONE_ASIO
namespace net = asio;
using system_error = std::system_error;
using error_code = std::error_code;

constexpr auto system_category = std::system_category;
#else // WINTLS_USE_STANDALONE_ASIO
namespace net = boost::asio;
using system_error = boost::system::system_error;
using error_code = boost::system::error_code;

constexpr auto system_category = boost::system::system_category;
#endif // !WINTLS_USE_STANDALONE_ASIO

} // namespace wintls
} // namespace boost

#endif // BOOST_WINTLS_DETAIL_CONFIG_HPP
