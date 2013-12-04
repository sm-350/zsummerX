/*
 * ZSUMMER_11X License
 * -----------
 * 
 * ZSUMMER_11X is licensed under the terms of the MIT license reproduced below.
 * This means that ZSUMMER_11X is free software and can be used for both academic
 * and commercial purposes at absolutely no cost.
 * 
 * 
 * ===============================================================================
 * 
 * Copyright (C) 2013 YaweiZhang <yawei_zhang@foxmail.com>.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * ===============================================================================
 * 
 * (end of COPYRIGHT)
 */


/*
 * AUTHORS:  YaweiZhang <yawei_zhang@foxmail.com>
 * VERSION:  1.0.0 beta
 * PURPOSE:  A lightweight C++ library for network.
 * CREATION: 2013.9.28
 * LCHANGE:  -
 * LICENSE:  Expat/MIT License, See Copyright Notice at the begin of this file.
 */


/*
 * Web Site: www.zsummer.net
 * mail: yawei_zhang@foxmail.com
 */


/*
 * UPDATES
 *
 *
 */


#ifndef _ZSUMMER_11X_ZSUMMER_H_
#define _ZSUMMER_11X_ZSUMMER_H_
#ifdef WIN32
#include "iocp/iocp_impl.h"
#else
#include "epoll/epoll_impl.h"
#endif

namespace zsummer
{
	namespace network
	{
		class CZSummer
		{
		public:
			CZSummer(){}
			~CZSummer(){}
			inline bool Initialize()
			{
				return m_impl.Initialize();
			}
			inline void RunOnce()
			{
				m_impl.RunOnce();
			}
			template<typename H>
			inline void Post(const H &h)
			{
				m_impl.Post(h);
			}
			template<typename H>
			inline unsigned long long CreateTimer(unsigned int delayms, const H &h)
			{
				return m_impl.CreateTimer(delayms, h);
			}
			inline bool CancelTimer(unsigned long long timerID)
			{
				return m_impl.CancelTimer(timerID);
			}
			friend class CTcpSocketImpl;
			friend class CUdpSocketImpl;
			friend class CTcpAcceptImpl;
		private:
			CZSummerImpl m_impl;
		};

	};
	
};























#endif











