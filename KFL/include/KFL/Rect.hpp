/**
 * @file Rect.hpp
 * @author Minmin Gong
 *
 * @section DESCRIPTION
 *
 * This source file is part of KFL, a subproject of KlayGE
 * For the latest info, see http://www.klayge.org
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * You may alternatively use this source under the terms of
 * the KlayGE Proprietary License (KPL). You can obtained such a license
 * from http://www.klayge.org/licensing/.
 */

#ifndef _KFL_RECT_HPP
#define _KFL_RECT_HPP

#pragma once

#include <KFL/PreDeclare.hpp>

#include <boost/operators.hpp>

#include <KFL/Vector.hpp>
#include <KFL/Size.hpp>

namespace KlayGE
{
	template <typename T>
	class Rect_T : boost::addable<Rect_T<T>,
						boost::addable2<Rect_T<T>, Vector_T<T, 2>,
						boost::subtractable<Rect_T<T>,
						boost::subtractable2<Rect_T<T>, Vector_T<T, 2>,
						boost::andable<Rect_T<T>,
						boost::orable<Rect_T<T>,
						boost::equality_comparable<Rect_T<T>>>>>>>>
	{
		template <typename U>
		friend class Rect_T;

	public:
		typedef T					value_type;

		typedef value_type*			pointer;
		typedef value_type const *	const_pointer;

		typedef value_type&			reference;
		typedef value_type const &	const_reference;

		typedef value_type*			iterator;
		typedef value_type const *	const_iterator;

		enum { elem_num = 4 };

	public:
		Rect_T() KLAYGE_NOEXCEPT
		{
		}
		explicit Rect_T(T const * rhs) KLAYGE_NOEXCEPT;
		// Leave them in header due to a compiling issue under GCC
		Rect_T(Rect_T const & rhs) KLAYGE_NOEXCEPT
			: rect_(rhs.rect_)
		{
		}
		template <typename U>
		Rect_T(Rect_T<U> const & rhs) KLAYGE_NOEXCEPT
			: rect_(rhs.rect_)
		{
		}
		Rect_T(Rect_T&& rhs) KLAYGE_NOEXCEPT;
		Rect_T(T left, T top, T right, T bottom) KLAYGE_NOEXCEPT;

		// 取向量
		reference left() KLAYGE_NOEXCEPT
		{
			return rect_[0];
		}
		const_reference left() const KLAYGE_NOEXCEPT
		{
			return rect_[0];
		}
		reference top() KLAYGE_NOEXCEPT
		{
			return rect_[1];
		}
		const_reference top() const KLAYGE_NOEXCEPT
		{
			return rect_[1];
		}
		reference right() KLAYGE_NOEXCEPT
		{
			return rect_[2];
		}
		const_reference right() const KLAYGE_NOEXCEPT
		{
			return rect_[2];
		}
		reference bottom() KLAYGE_NOEXCEPT
		{
			return rect_[3];
		}
		const_reference bottom() const KLAYGE_NOEXCEPT
		{
			return rect_[3];
		}

		// 赋值操作符
		template <typename U>
		Rect_T const & operator+=(Vector_T<U, 2> const & rhs) KLAYGE_NOEXCEPT;
		template <typename U>
		Rect_T const & operator-=(Vector_T<U, 2> const & rhs) KLAYGE_NOEXCEPT;
		template <typename U>
		Rect_T const & operator+=(Rect_T<U> const & rhs) KLAYGE_NOEXCEPT;
		template <typename U>
		Rect_T const & operator-=(Rect_T<U> const & rhs) KLAYGE_NOEXCEPT;
		template <typename U>
		Rect_T const & operator&=(Rect_T<U> const & rhs) KLAYGE_NOEXCEPT;
		template <typename U>
		Rect_T const & operator|=(Rect_T<U> const & rhs) KLAYGE_NOEXCEPT;

		// Leave them in header due to a compiling issue under GCC
		Rect_T& operator=(Rect_T const & rhs) KLAYGE_NOEXCEPT
		{
			if (this != &rhs)
			{
				rect_ = rhs.rect_;
			}
		return *this;
		}
		template <typename U>
		Rect_T& operator=(Rect_T<U> const & rhs) KLAYGE_NOEXCEPT
		{
			rect_ = rhs.rect_;
			return *this;
		}
		Rect_T& operator=(Rect_T&& rhs) KLAYGE_NOEXCEPT;

		// 一元操作符
		Rect_T const operator+() const KLAYGE_NOEXCEPT;
		Rect_T const operator-() const KLAYGE_NOEXCEPT;

		// 属性
		T Width() const KLAYGE_NOEXCEPT;
		T Height() const KLAYGE_NOEXCEPT;
		Size_T<T> const Size() const KLAYGE_NOEXCEPT;
		bool IsEmpty() const KLAYGE_NOEXCEPT;

		bool operator==(Rect_T<T> const & rhs) const KLAYGE_NOEXCEPT;

		bool PtInRect(Vector_T<T, 2> const & pt) const KLAYGE_NOEXCEPT;

	private:
		Vector_T<T, elem_num> rect_;
	};
}

#endif			// _KFL_RECT_HPP
