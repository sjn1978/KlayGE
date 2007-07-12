// OggSource.hpp
// KlayGE Ogg音频数据源 头文件
// Ver 3.6.0
// 版权所有(C) 龚敏敏, 2003-2007
// Homepage: http://klayge.sourceforge.net
//
// 3.6.0
// 用vorbisfile重写，可以返回原始大小 (2007.7.12)
//
// 2.0.0
// 初次建立 (2003.7.7)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#ifndef _OGGSOURCE_HPP
#define _OGGSOURCE_HPP

#define KLAYGE_LIB_NAME KlayGE_AudioDataSource_OggWav
#include <KlayGE/config/auto_link.hpp>

#include <KlayGE/PreDeclare.hpp>

#include <KlayGE/AudioDataSource.hpp>

#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>

namespace KlayGE
{
	class OggSource : public AudioDataSource
	{
	public:
		explicit OggSource(ResIdentifierPtr const & file);
		~OggSource();

		size_t Size();

		size_t Read(void* data, size_t size);
		void Reset();

	private:
		static size_t VorbisRead(void* ptr, size_t byteSize, size_t sizeToRead, void* datasource);
		static int VorbisSeek(void* datasource, ogg_int64_t offset, int whence);
		static int VorbisClose(void* datasource);
		static long VorbisTell(void* datasource);

	private:
		ResIdentifierPtr		oggFile_;
		std::istream::pos_type	length_;

		OggVorbis_File vf_;
	};
}

#endif			// _OGGSOURCE_HPP
