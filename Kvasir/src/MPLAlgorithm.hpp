#pragma once
#include "MPLTypes.hpp"
namespace Kvasir {
namespace MPL {
	namespace Detail {
		//default only reached when Ts is empty
		template<int I, typename T_Find, typename ... Ts>
		struct Find: Int<-1> {
		};
		//T_Find does not match first of Ts
		template<int I, typename T_Find, typename T, typename ... Ts>
		struct Find<I, T_Find, T, Ts...> : Find<I + 1, T_Find, Ts...> {};
		//T_Find matches first of Ts
		template<int I, typename T_Find, typename ... Ts>
		struct Find<I, T_Find, T_Find, Ts...> : Int<I> {};

		//default only reached when Ts is empty
		template<int I, bool Found, template<typename...> class Pred, typename ... Ts>
		struct PredFind: Int<-1> {
		};
		template<int I, template<typename...> class Pred, typename T, typename...Ts>
		struct PredFind<I,true,Pred,T,Ts...> : Int<I>{};
		template<int I, template<typename...> class Pred, typename T, typename ... Ts>
		struct PredFind<I, false, Pred, T, Ts...> : PredFind<I + 1, Pred<T>::value,Pred, Ts...> {};

		template<typename TOut, typename TDelim, typename... Ts>
		struct Join{
			static_assert(AlwaysFalse<TOut>::value,"Incorrect parameter format, expected list of lists");
		};
		template<typename... Os, typename TDelim, typename... Ls, typename... Ts>
		struct Join<List<Os...>,TDelim,List<Ls...>,Ts...> : Join<List<Os...,TDelim,Ls...>,TDelim,Ts...>{};
		template<typename... Os, typename TDelim>
		struct Join<List<Os...>,TDelim> : List<Os...>{};   //no more input, done

		template<typename TOut, typename TCurrent, typename TDelim, typename... Ts>
		struct Split;
		template<typename... Os, typename... Cs, typename TDelim, typename T, typename... Ts>
		struct Split<List<Os...>,List<Cs...>,TDelim,T,Ts...> : //next is not delim, we still have more
			Split<List<Os...>,List<Cs...,T>,TDelim,Ts...>{};
		template<typename... Os, typename... Cs, typename TDelim, typename T>
		struct Split<List<Os...>,List<Cs...>,TDelim,T> : //next is not delim, we do not have more
			List<Os...,List<Cs...,T>>{};
		template<typename... Os, typename... Cs, typename TDelim, typename... Ts>
		struct Split<List<Os...>,List<Cs...>,TDelim,TDelim,Ts...> : //next is delim, we still have more
			Split<List<Os...,List<Cs...>>,List<>,TDelim,Ts...>{};
		template<typename... Os, typename... Cs, typename TDelim>
		struct Split<List<Os...>,List<Cs...>,TDelim,TDelim> : //next is delim, we have no more
			List<Os...,List<Cs...>>{};
		//same cases but with empty TCurrent list
		template<typename... Os, typename TDelim, typename... Ts>
		struct Split<List<Os...>,List<>,TDelim,TDelim,Ts...> : //next is delim, we still have more
			Split<List<Os...>,List<>,TDelim,Ts...>{};
		template<typename... Os, typename TDelim>
		struct Split<List<Os...>,List<>,TDelim,TDelim> : //next is delim, we have no more
			List<Os...>{};

		//default only reached when Ts is empty
		template<typename T_List, typename ... Ts>
		struct Flatten: T_List {};
		//first of Ts is not a list
		template<typename ... Ts, typename T, typename ... Us>
		struct Flatten<List<Ts...>, T, Us...> : Flatten<List<Ts..., T>, Us...> {};
		//frist of Ts is a list
		template<typename ... Ts, typename ... Us, typename ... Vs>
		struct Flatten<List<Ts...>, List<Us...>, Vs...> :
			Flatten<List<Ts...>, Us..., Vs...> {};

		template<typename T_Out, template<typename, typename > class T_Pred,
				typename T_Insert, bool B_Tag, typename ... Ts>
		struct SortInsert;
		//next is less than insert, next is not end
		template<typename ... Os, template<typename, typename > class T_Pred,
				typename T_Insert, typename T1, typename T2, typename ... Ts>
		struct SortInsert<List<Os...>, T_Pred, T_Insert, true, T1, T2, Ts...> : SortInsert<
				List<Os..., T1>, T_Pred, T_Insert, T_Pred<T2, T_Insert>::value, T2,
				Ts...> {
		};
		//next is less than insert, next is end, terminate
		template<typename ... Os, template<typename, typename > class T_Pred,
				typename T_Insert, typename ... Ts>
		struct SortInsert<List<Os...>, T_Pred, T_Insert, true, Ts...> : List<Os...,
				Ts..., T_Insert> {
		};
		//next is not less than insert, terminate
		template<typename ... Os, template<typename, typename > class T_Pred,
				typename T_Insert, typename ... Ts>
		struct SortInsert<List<Os...>, T_Pred, T_Insert, false, Ts...> : List<Os...,
				T_Insert, Ts...> {
		};

		template<typename TOut, template<typename, typename > class P, typename ... Ts>
		struct Sort{
			static_assert(AlwaysFalse<TOut>::value,"implausible parameters");
		};
		//out and in are not empty
		template<typename O, typename ... Os,
				template<typename, typename > class TPred, typename TInsert,
				typename ... Ts>
		struct Sort<List<O, Os...>, TPred, TInsert, Ts...> : Sort<
				typename Detail::SortInsert<List<>, TPred, TInsert,
						TPred<O, TInsert>::value, O, Os...>::Type, TPred, Ts...> {
		};
		//out is empty, in is not empty
		template<typename ... Os, template<typename, typename > class TPred,
				typename TInsert, typename ... Ts>
		struct Sort<List<Os...>, TPred, TInsert, Ts...> : Sort<
				typename Detail::SortInsert<List<>, TPred, TInsert, false, Os...>::Type,
				TPred, Ts...> {
		};
		//in is empty
		template<typename ... Os, template<typename, typename > class P, typename ... Ts>
		struct Sort<List<Os...>, P, Ts...> : List<Os...> {
		};

		template<typename TOut, int From, int To, typename... Ts>
		struct Remove;
		template<typename... Os, int From, int To, typename T, typename... Ts>
		struct Remove<List<Os...>,From,To,T,Ts...> : Remove<List<Os...,T>,From-1,To-1,Ts...>{};
		template<typename... Os, int To, typename T, typename... Ts>
		struct Remove<List<Os...>,0,To,T,Ts...> : Remove<List<Os...>,0,To-1,Ts...>{};
		template<typename... Os, typename T, typename... Ts>
		struct Remove<List<Os...>,0,0,T,Ts...> : List<Os...,T,Ts...>{};
		template<typename... Os>
		struct Remove<List<Os...>,0,0> : List<Os...>{};

	}

	//Find returns Int<-1> if type is not found, otherwise returns index
	template<typename TList, typename TToFind>
	struct Find{
		static_assert(AlwaysFalse<TToFind>::value,"implausible parameters");
	};
	template<typename T, typename ... Ts>
	struct Find<List<Ts...>,T> : Detail::Find<0, T, Ts...> {
	};
	template<template<typename...> class Pred, typename T, typename... Ts>
	struct Find<List<T,Ts...>, Template<Pred>> : Detail::PredFind<0,Pred<T>::value,Pred,Ts...>{};
	template<typename TList, typename TToFind>
	using FindT = typename Find<TList,TToFind>::Type;

	//returns true if T_ToFind is in T_Container, otherwise false
	template<typename TContainer, typename TToFind>
	struct Contains{
		static_assert(AlwaysFalse<TToFind>::value,"implausible type");
	};
	template<typename TToFind, typename ... Ts>
	struct Contains<List<Ts...>,TToFind> : NotT<
			IsSameT<typename Detail::Find<0, TToFind, Ts...>::Type, Int<-1>>> {};
	template<typename TContainer, typename TToFind>
	using ContainsT = typename Contains<TContainer,TToFind>::Type;

	//works like PHP explode, splits a list into a list of lists devided by a user provided delimiter
	template<typename TList, typename TDelim>
	struct Split {
		static_assert(AlwaysFalse<TList>::value,"implausible parameters");
	};
	template<typename... Ts, typename TDelim>
	struct Split<List<Ts...>,TDelim> : Detail::Split<List<>, List<>,TDelim,Ts...>{};

	template<typename TList, typename TDelim>
	using SplitT = typename Split<TList,TDelim>::Type;

	//works like PHP implode, merges a list of lists into a list divided by a user provided delimiter
	template<typename TList, typename TDelim>
	struct Join {
		static_assert(AlwaysFalse<TList>::value,"implausible parameters");
	};
	template<typename... Ts, typename TDelim>
	struct Join<List<Ts...>,TDelim> : Detail::Join<List<>, List<>,TDelim,Ts...>{};

	template<typename TList, typename TDelim>
	using JoinT = typename Join<TList,TDelim>::Type;

	//if a type is a list of types it will successively be unpacked into the enclosing list
	template<typename TList>
	struct Flatten{
		static_assert(AlwaysFalse<TList>::value,"implausible type");
	};
	template<typename ... Ts>
	struct Flatten<List<Ts...>> : Detail::Flatten<List<>, Ts...> {
	};
	template<typename TList>
	using FlattenT = typename Flatten<TList>::Type;

	//Sort
	template<typename TList, typename TPred = LessP>
	struct Sort{
		static_assert(AlwaysFalse<TList>::value,"implausible type");
	};

	//empty input case
	template<template<typename, typename > class TPred>
	struct Sort<MPL::List<>, Template<TPred>> : List<> {};

	//one element case
	template<typename T, template<typename, typename > class TPred>
	struct Sort<MPL::List<T>, Template<TPred>> : List<T> {};

	//two or more elements case
	template<typename ... Ts, template<typename, typename > class TPred>
	struct Sort<MPL::List<Ts...>, Template<TPred>> :
		Detail::Sort<List<>, TPred,	Ts...> {};

	//alias
	template<typename TList, typename TPred = LessP>
	using SortT = typename Sort<TList,TPred>::Type;

	template<typename TList, typename TIndex>
	struct At{
		static_assert(AlwaysFalse<TList>::value,"implausible parameters");
	};
	template<typename T, typename...Ts, int I>
	struct At<List<T, Ts...>,Int<I>> : At<List<Ts...>,Int<I-1>>{};
	template<typename T, typename... Ts>
	struct At<List<T, Ts...>,Int<0>> : T{};
	template<typename TList, typename TIndex>
	using AtT = typename At<TList,TIndex>::Type;

	template<typename TList, typename TFrom, typename TTo>
	struct Remove{
		static_assert(AlwaysFalse<TList>::value,"implausible parameters");
	};
	template<typename T, typename... Ts, int From, int To>
	struct Remove<List<T, Ts...>,Int<From>,Int<To>> : Detail::Remove<List<>,From,To,T,Ts...>{};

	template<typename TList,typename TFrom, typename TTo>
	using RemoveT = typename Remove<TList,TFrom,TTo>::Type;



}
}
