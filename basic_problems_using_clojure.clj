;;https://codeforces.com/contest/1513/problem/A

(ns learn-clojure.core
  (:gen-class))

(defn permutation [data k n]
  (if (and (odd? n) (> k (/ n 2))) [-1] (if (and (even? n) (> k (/ (- n 1) 2))) [-1]

                                            (loop [final '[] item data cnt 1]
                                              (if (empty? item) final
                                                  (if (and (even? cnt) (<= cnt (* 2 k))) (recur   (conj final (last item)) (drop-last item) (inc cnt))

                                                      (recur (conj final (first item)) (next item) (inc cnt))))))))

(defn parse [] (let [data (read-line)]
                 (mapv #(Long/parseLong %) (clojure.string/split data #" "))))

(defn -main [] (def tt (Integer/parseInt (read-line)))
  (dotimes [_ tt] (let [[n k] (parse)]
                    (apply println (permutation  (map inc (range n)) k n)))))


