#pragma once

class IMover abstract
{
public:
	virtual auto moveTo(crd row, crd col) -> void = 0;
	virtual auto directTo(crd row, crd col) -> void = 0;
	//virtual auto blinkTo(size_t row, size_t col) -> void = 0;


};

