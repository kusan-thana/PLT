
template <class E, typename ID>
ElementAlloc<E,ID>::ElementAlloc(ID id) : id(id) {
}

template <class E, typename ID>
Element* ElementAlloc<E,ID>::newInstance(){

	return (new E(id));
}
