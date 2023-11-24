/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "base/weak_ptr.h"
#include "ui/chat/chat_style.h"

class Painter;

namespace Data {
class Story;
} // namespace Data

namespace Ui {
class RippleAnimation;
} // namespace Ui

namespace Media::Stories {

class Controller;

class RepostView final : public base::has_weak_ptr {
public:
	RepostView(
		not_null<Controller*> controller,
		not_null<Data::Story*> story);
	~RepostView();

	[[nodiscard]] int height() const;
	void draw(Painter &p, int x, int y, int availableWidth);

private:
	void recountDimensions();

	const not_null<Controller*> _controller;
	const not_null<Data::Story*> _story;
	std::unique_ptr<Ui::RippleAnimation> _ripple;

	Ui::Text::String _name;
	Ui::Text::String _text;
	Ui::Text::QuotePaintCache _quoteCache;
	Ui::BackgroundEmojiData _backgroundEmojiData;
	QString _stateText;
	Ui::ColorIndicesCompressed _colorIndices;
	int _maxWidth = 0;

	rpl::lifetime _lifetime;

};

} // namespace Media::Stories
