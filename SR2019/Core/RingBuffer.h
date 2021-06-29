/*
 * RingBuffer.h
 *
 * Created: 3/26/2019 21:10:38
 *  Author: T510
 */ 


#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

template <uint8_t buffer_size> 
class RingBuffer
{
	public:
	
	RingBuffer() : _head(0), _tail(0){
		memset(_buffer, 0, buffer_size);
	}
	
	void store(uint8_t c){
		uint8_t i = (_head + 1) % buffer_size;
		if (i != _tail)
		{
			_buffer[_head] = c;
			_head = i;
		}
	}
	int available(void) const{	
		return (buffer_size + _head - _tail) % buffer_size; 
	}

	int peek(void) const{
		if (_head == _tail)
		return -1;
		else
		return _buffer[_tail];
	}
	int read(void){
		if (_head == _tail)
		return -1;
		else
		{
			uint8_t c = _buffer[_tail];
			_tail = (_tail + 1) % buffer_size;
			return c;
		}
	}
	void flush(void)
	{
		_head = _tail;
	}

	public:
	unsigned char _buffer[buffer_size];
	volatile uint8_t _head;
	volatile uint8_t _tail;
};

#endif /* RINGBUFFER_H_ */