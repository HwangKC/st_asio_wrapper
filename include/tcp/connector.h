/*
 * connector.h
 *
 *  Created on: 2012-3-2
 *      Author: youngwolf
 *		email: mail2tao@163.com
 *		QQ: 676218192
 *		Community on QQ: 198941541
 *
 * this class only used at client endpoint
 */

#ifndef ST_ASIO_CONNECTOR_H_
#define ST_ASIO_CONNECTOR_H_

#include "client_socket.h"

namespace st_asio_wrapper { namespace tcp {

template <typename Packer, typename Unpacker, typename Socket = boost::asio::ip::tcp::socket,
	template<typename, typename> class InQueue = ST_ASIO_INPUT_QUEUE, template<typename> class InContainer = ST_ASIO_INPUT_CONTAINER,
	template<typename, typename> class OutQueue = ST_ASIO_OUTPUT_QUEUE, template<typename> class OutContainer = ST_ASIO_OUTPUT_CONTAINER>
class connector_base : public client_socket_base<Packer, Unpacker, Socket, InQueue, InContainer, OutQueue, OutContainer>
{
private:
	typedef client_socket_base<Packer, Unpacker, Socket, InQueue, InContainer, OutQueue, OutContainer> super;

public:
	connector_base(boost::asio::io_service& io_service_) : super(io_service_) {}
	template<typename Arg> connector_base(boost::asio::io_service& io_service_, Arg& arg) : super(io_service_, arg) {}
};

}} //namespace

#endif /* ST_ASIO_CONNECTOR_H_ */
