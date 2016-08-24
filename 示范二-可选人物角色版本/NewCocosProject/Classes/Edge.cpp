//
//  Edge.cpp
//  NoOneDies
//
//  Created by plter on 14-6-2.
//
//

#include "Edge.h"


bool Edge::init() {

	Node::init();
	//��ʼ���ذ�
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size edgeSize = Size(visibleSize.width, 1);
	setPhysicsBody(PhysicsBody::createEdgeBox(edgeSize));
	setContentSize(edgeSize);
	return true;
}