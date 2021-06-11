import Int "mo:base/Int";
import Time "mo:base/Time";
import Array "mo:base/Array";
import Random "mo:base/Random";
import Nat8 "mo:base/Nat8";
import List "mo:base/List";
import Nat32 "mo:base/Nat32";
import Text "mo:base/Text";
import TrieSet "mo:base/TrieSet";
import Hash "mo:base/Hash";

actor {
    //private var array : Array.Array<Nat8> = [0];
    private var list = List.nil<Nat32>(); 
    private var b : Blob = Text.encodeUtf8("");
    private let array = Array.init<Nat>(100000, 0);

    private var random : Random.Finite = Random.Finite(b);

    private func createList() : Text{
        var i : Nat32 = 10000;
        let before = Time.now();
        while (i != Nat32.fromNat(0)) {
            list := List.append(list, ?(i, null));
            i-=1;
        };
        let end = Time.now();
        let elapsedSeconds = end - before ;
        Int.toText(elapsedSeconds) # " " # "before" # Int.toText(before) # "end " # Int.toText(end)
    };

    public query func findListNumber() : async Text{
        //average time
        var create_time = createList();
        
        //time
        var i = 100;
        //let before = Time.now();
        while (i != 0){
            var randomNumber = switch(random.range(Nat8.fromNat(13))){
                case (?num) { num };
                case _ { 0 };
            };
            var r_num = Nat32.fromNat(randomNumber);
            switch(List.find<Nat32>(list, func (n :Nat32) : Bool{
                if (n == r_num) { true }
                else{ false }
            })){
                case (?num) { () };
                case _ { () };
            };
            i -= 1;
        };
        "finish list search"
        //let after = Time.now();
        //let elapsedSeconds = after - before;
        //"find time : " # Int.toText(elapsedSeconds) # create_time
    };

    private func createArray(){
        var a = 100000;
        while (a != 0) {
            array[a-1] := a;
            a -= 1;
        }
    };

    public query func findArrayNumbe() : async Text{
        createArray();
        var i = 100;
        while (i != 0){
            var randomNumber = switch(random.range(Nat8.fromNat(13))){
                case (?num) { num };
                case _ { 0 };
            };
            label t for (num in array.vals()) { 
                if (num == randomNumber) {
                    break t
                }
            };
            i -= 1;
        };
        "finish array search"
    };
};