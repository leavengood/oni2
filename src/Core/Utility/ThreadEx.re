open Kernel;

let waitForCondition = (~timeout=1.0, f) => {
  let thread =
    ThreadHelper.create(
      ~name="Utility.waitForCondition",
      () => {
        let s = Unix.gettimeofday();
        while (!f() && Unix.gettimeofday() -. s < timeout) {
          Unix.sleepf(0.0005);
        };
      },
      (),
    );

  Thread.join(thread);
};
