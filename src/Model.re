module Player = {
    type t = {
        position: array(int)
    }
}

module Board = {
    type re = {
        ground: array(array(int))
    }
}

module Car = {
    type t = {
        position: list(array(int))
    }
}

module State = {
    type t =  {
        playerPosition: (int, int),
        ground: array(array(int))
    }

    let initial_state = {
        playerPosition: (0, 0),
        ground: Array.make_matrix(15, 9, 0)
    }


    let changePoint = (point, axis, func) => {
        Js.log(0 <= point);
        switch (axis) {
        | "yaxis" => {
            if (point <= 0) {
                point + 1;
            } else if (point < 14) {
                func(point, 1)
            } else if (point == 14) {
                point - 1;
            } else {
                func(point, 0);
            }
        };
        | "xaxis" => {
            if (point <= 0) {
                point + 1;
            } else if (point < 8) {
                func(point, 1)
            } else if (point == 8) {
                point - 1;
            } else {
                func(point, 0);
            }
        };
        }
    };

    let reducer = (state, action) => {
        let (y, x) = state.playerPosition;
Js.log(state.playerPosition);
        let new_state = switch (action) {
        | "up" => {
            state.ground[y][x] = 0;
            let y = changePoint(y, "yaxis", (-));
            {
                ...state,
                playerPosition: (y, x)
            }};
        | "down" => {
            state.ground[y][x] = 0;
            let y = changePoint(y, "yaxis", (+));
            {
                ...state,
                playerPosition: (y, x)
            }};
        | "left" => {
            state.ground[y][x] = 0;
            let x = changePoint(x, "xaxis", (-));
            {
                ...state,
                playerPosition: (y, x) 
            }};
        | "right" => {
            state.ground[y][x] = 0;
            let x = changePoint(x, "xaxis", (+));
            {
                ...state,
                playerPosition: (y, x)
            }};
        };

        new_state;
    }
}